module CounterAPI = {
  let then_ a b => ReasonJs.Promise.thenDo b a;
  let fetchAndUpdate action updateState => {
    let p = ReasonJs.fetch ("https://rehydrate-workshop-server-coescnwddb.now.sh/" ^ action);
    let _ = p |> then_ ReasonJs.Response.text |> then_ updateState;
    ()
  };
  let getCount updateState => {
    fetchAndUpdate "count" updateState;
    ()
  };
  let incrementCount updateState => {
    fetchAndUpdate "increment" updateState;
    ()
  };
  let decrementCount updateState => {
    fetchAndUpdate "decrement" updateState;
    ()
  };
};

module Page = {
  module GroupCounter = {
    include ReactRe.Component.Stateful;
    include CounterAPI;
    let name = "GroupCounter";
    type state = {count: int};
    type props = unit;
    let getInitialState props => {count: 0};
    let stateUpdater updater str => updater (fun _ e => Some {count: int_of_string str}) ();
    let componentDidMount {updater} => {
      let _ = ReasonJs.setInterval (fun () => getCount (stateUpdater updater)) 500;
      None
    };
    let handleIncrement {updater} event => {
      incrementCount (stateUpdater updater);
      None
    };
    let handleDecrement {updater} event => {
      decrementCount (stateUpdater updater);
      None
    };
    let render {props, state, updater} =>
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
