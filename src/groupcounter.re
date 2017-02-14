module CounterAPI = {
  /* TODO - write the then_ helper */
  /* TODO - write the fetch and update function */
  /* TODO - handle promise result with then_ */
  /* NOTE - API link: "https://rehydrate-workshop-server-coescnwddb.now.sh/" */
  /* TODO - write getCount, incrementCount, and decrementCount for consumption */
};

module GroupCounter = {
  include ReactRe.Component.Stateful.InstanceVars;
  let name = "GroupCounter";
  type props = unit;

  /** state */
  type state = {count: int};
  let getInitialState _ => {count: 0};

  /** instanceVars */
  type instanceVars = {mutable intervalID: option ReasonJs.intervalId};
  let getInstanceVars () => {intervalID: None};

  /** count setting callback */
  let countSetter setState str => setState (fun _ => {count: int_of_string str});

  /** lifecycle methods */
  /* TODO - begin setInterval when component mounts */
  /* TODO - take care of tear down logic */
  /* TODO - call API for each setInterval */

  /** event handlers */
  let handleIncrement {setState} _ => {
    /* TODO - call API to increment */
    Js.log "increment";
    None
  };
  let handleDecrement {setState} _ => {
    /* TODO - call API to decrement */
    Js.log "decrement";
    None
  };

  /** render */
  let render {state, updater} =>
    <div>
      <h1> (ReactRe.stringToElement (string_of_int state.count)) </h1>
      <button onClick=(updater handleIncrement)> (ReactRe.stringToElement "Increment") </button>
      <button onClick=(updater handleDecrement)> (ReactRe.stringToElement "Decrement") </button>
    </div>;
};

include ReactRe.CreateComponent GroupCounter;

let createElement = wrapProps ();

let () =
  ReactDOMRe.render (createElement children::[] ()) (ReasonJs.Document.getElementById "index");
