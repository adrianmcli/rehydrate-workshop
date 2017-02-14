module MessageAdapter = {
  /* TODO - write a submit function to send the message to the API */
  /* NOTE - API URL: "https://rehydrate-workshop-board-server-vfxanxldvd.now.sh/message/" */
};

module Input2 = {
  include ReactRe.Component.Stateful;
  open MessageAdapter;
  let name = "Input2";
  type state = {input: string};
  type props = unit;
  let getInitialState _ => {input: ""};

  /** input change handler */
  /* TODO - fix change handler to have a controlled component */
  let handleInputChange _ event => None;

  /** key down handler */
  let handleKeyDown {state, updater} event => {
    let clearInput = updater (fun _ _ => Some {input: ""});
    /* TODO - use pattern matching to submit message on enter key down */
    None
  };

  /** render */
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

let () =
  ReactDOMRe.render (createElement children::[] ()) (ReasonJs.Document.getElementById "index");
