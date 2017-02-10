module CounterAPI = {
  let then_ a b => ReasonJs.Promise.thenDo b a;
  let fetchAndUpdate action updateState => {
    let p = ReasonJs.fetch ("https://rehydrate-workshop-server-coescnwddb.now.sh/" ^ action);
    let _ = p |> then_ ReasonJs.Response.text |> then_ updateState;
    ()
  };
  let getCount = fetchAndUpdate "count";
  let incrementCount = fetchAndUpdate "increment";
  let decrementCount = fetchAndUpdate "decrement";
};

module Page = {
  module GroupCounter = {
    include ReactRe.Component.Stateful.InstanceVars;
    let name = "GroupCounter";
    type props = unit;

    /* state */
    type state = {count: int};
    let getInitialState props => {count: 0};

    /* instanceVars */
    type instanceVars = {mutable intervalID: option ReasonJs.intervalId};
    let getInstanceVars () => {intervalID: None};

    /* count updater callback */
    let countUpdater updater str => updater (fun _ e => Some {count: int_of_string str}) ();

    /* lifecycle methods */
    let componentDidMount {instanceVars, updater} => {
      let intervalID =
        ReasonJs.setInterval (fun () => CounterAPI.getCount (countUpdater updater)) 500;
      instanceVars.intervalID = Some intervalID;
      None
    };
    let componentWillUnmount {instanceVars} =>
      switch instanceVars.intervalID {
      | None => ()
      | Some id => ReasonJs.clearInterval id
      };

    /* event handlers */
    let handleIncrement {updater} event => {
      CounterAPI.incrementCount (countUpdater updater);
      None
    };
    let handleDecrement {updater} event => {
      CounterAPI.decrementCount (countUpdater updater);
      None
    };

    let render {state, updater} =>
      <div>
        <h1> (ReactRe.stringToElement (string_of_int state.count)) </h1>
        <button onClick=(updater handleIncrement)> (ReactRe.stringToElement "Increment") </button>
        <button onClick=(updater handleDecrement)> (ReactRe.stringToElement "Decrement") </button>
      </div>;
  };
  include ReactRe.CreateComponent GroupCounter;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
