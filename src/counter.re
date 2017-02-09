module Page = {
  module Counter = {
    include ReactRe.Component.Stateful;
    let name = "Counter";
    type state = {count: int, input: string};
    type props = unit;
    let getInitialState props => {count: 0, input: ""};
    /* increment handler */
    let handleIncrement {state, updater} event => {
      Js.log "clicked increment!";
      Some {...state, count: state.count + 1}
    };
    /* decrement handler */
    let handleDecrement {state, updater} event => {
      Js.log "clicked decrement!";
      Some {...state, count: state.count - 1}
    };
    let render {props, state, updater} =>
      <div>
        <h1> (ReactRe.stringToElement (string_of_int state.count)) </h1>
        <button onClick=(updater handleIncrement)> (ReactRe.stringToElement "Increment") </button>
        <button onClick=(updater handleDecrement)> (ReactRe.stringToElement "Decrement") </button>
      </div>;
  };
  include ReactRe.CreateComponent Counter;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
