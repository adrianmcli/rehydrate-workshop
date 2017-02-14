module Page = {
  /* module Counter = {
       include ReactRe.Component.Stateful;
       let name = "Counter";
       type state = {count: int};
       type props = unit;
       let getInitialState _ => {count: 0};

       /** increment handler */
       let handleIncrement {state} _ => {
         Js.log "clicked increment!";
         Some {count: state.count + 1}
       };

       /** decrement handler */
       let handleDecrement {state} _ => {
         Js.log "clicked decrement!";
         Some {count: state.count - 1}
       };

       /** render */
       let render {state, updater} =>
         <div>
           <h1> (ReactRe.stringToElement (string_of_int state.count)) </h1>
           <button onClick=(updater handleIncrement)> (ReactRe.stringToElement "Increment") </button>
           <button onClick=(updater handleDecrement)> (ReactRe.stringToElement "Decrement") </button>
         </div>;
     }; */
  include ReactRe.CreateComponent Counter;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
