// let _ = [%bs.raw {|window.LOG_LEVEL = "DEBUG"|}];
type window;

[@bs.val] external window: window = "window";

[@bs.val] [@bs.scope "window"] external loglevel: string = "LOG_LEVEL";
[@bs.set] external setLogLevel: (window, string) => unit = "LOG_LEVEL";
/* this returns the value of `loglevel`! Did not know this syntax */
let loglevel = () => loglevel;
let setLogLevel = setLogLevel(window,"DEBUG");
Js.log2("loglevel", loglevel());
Amplify.configure(Amplify.Config.awsConfig);

ReactDOMRe.renderToElementWithId(<App />, "root");