module Page = {
  module Foo = {
    include ReactRe.Component;
    let name = "Foo";
    type props = {message: string};
    let render {props} => <div> (ReactRe.stringToElement props.message) </div>;
  };
  include ReactRe.CreateComponent Foo;
  let createElement ::message => wrapProps {message: message};
};

let () = ReactDOMRe.render <Page message="hello" /> (ReasonJs.Document.getElementById "index");
