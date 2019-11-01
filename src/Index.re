type window;

[@bs.val] external window: window = "window";

[@bs.val] [@bs.scope "window"] external loglevel: string = "LOGLEVEL";
[@bs.set] external setLogLevel: (window, string) => unit = "LOGLEVEL";

let loglevel = () => loglevel;
let setLogLevel = setLogLevel(window);
Amplify.configure(Amplify.Config.awsConfig);
ReactDOMRe.renderToElementWithId(<App />, "root");