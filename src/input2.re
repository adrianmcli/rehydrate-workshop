module MessageAdapter = {
  let submitMessage message => Js.log message;
};

module Page = {
  module Input2 = {
    include ReactRe.Component.Stateful;
    include MessageAdapter;
    let name = "Input2";
    type state = {input: string};
    type props = unit;
    let getInitialState props => {input: ""};
    let handleInputChange {state} event => Some {input: ReasonJs.Document.value event##target};
    let handleKeyDown {state, updater} event => {
      let clearInput = updater (fun {state} e => Some {input: ""});
      switch event##keyCode {
      | 13 =>
        submitMessage state.input;
        clearInput ()
      | _ => ()
      };
      None
    };
    let render {state, updater} =>
      <div>
        <input
          onChange=(updater handleInputChange)
          onKeyDown=(updater handleKeyDown)
          value=state.input
        />
        <h1> (ReactRe.stringToElement state.input) </h1>
      </div>;
  };
  include ReactRe.CreateComponent Input2;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
