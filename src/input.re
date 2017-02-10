module Input = {
  include ReactRe.Component.Stateful;
  let name = "Input";
  type state = {display: string};
  type props = unit;
  let getInitialState _ => {display: "Please type something."};

  /** input handler */
  let handleInputChange _ event => {
    let inputStr = ReasonJs.Document.value event##target;

    /** pattern matching example */
    let displayStr =
      switch inputStr {
      | "" => "Please type something."
      | " " => "A space is not something!"
      | _ => "input: " ^ inputStr
      };
    Some {display: displayStr}
  };

  /** render */
  let render {state, updater} =>
    <div>
      <input onChange=(updater handleInputChange) />
      <h1> (ReactRe.stringToElement state.display) </h1>
    </div>;
};

include ReactRe.CreateComponent Input;

let createElement = wrapProps ();

let () =
  ReactDOMRe.render (createElement children::[] ()) (ReasonJs.Document.getElementById "index");
