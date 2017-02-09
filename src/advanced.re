module Page = {
  module Advanced = {
    include ReactRe.Component.Stateful;
    let name = "Advanced";
    type state = {input: string};
    type props = unit;
    let getInitialState props => {input: "Please type something."};
    let submitMessage message => Js.log message;
    let handleInputChange {state} event => Some {input: ReasonJs.Document.value event##target};
    let handleKeyDown {state, updater} event => {
      let clearInput = updater (fun {state} e => Some {input: ""}) ();
      switch event##keyCode {
      | 13 =>
        submitMessage state.input;
        clearInput
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
  include ReactRe.CreateComponent Advanced;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
