module MessageAdapter = {
  let submitMessage message => {
    let baseUrl = "https://rehydrate-workshop-board-server-vfxanxldvd.now.sh/message/";
    let _ = ReasonJs.fetch (baseUrl ^ message);
    ()
  };
};

module Input2 = {
  include ReactRe.Component.Stateful;
  open MessageAdapter;
  let name = "Input2";
  type state = {input: string};
  type props = unit;
  let getInitialState _ => {input: ""};

  /** input change handler */
  let handleInputChange _ event => Some {input: ReasonJs.Document.value event##target};

  /** key down handler */
  let handleKeyDown {state, updater} event => {
    let clearInput = updater (fun _ _ => Some {input: ""});
    switch event##keyCode {
    /* pattern match for enter key */
    | 13 =>
      submitMessage state.input;
      clearInput ()
    | _ => ()
    };
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
