module Page = {
  module Input = {
    include ReactRe.Component.Stateful;
    let name = "Input";
    type state = {display: string};
    type props = unit;
    let getInitialState props => {display: "Please type something."};
    /* input handler */
    let handleInputChange {state} event => {
      let inputStr = ReasonJs.Document.value event##target;
      let displayStr =
        switch inputStr {
        | "" => "Please type something."
        | " " => "A space is not something!"
        | _ => "input: " ^ inputStr
        };
      Some {display: displayStr}
    };
    let render {state, updater} =>
      <div>
        <input onChange=(updater handleInputChange) />
        <h1> (ReactRe.stringToElement state.display) </h1>
      </div>;
  };
  include ReactRe.CreateComponent Input;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");