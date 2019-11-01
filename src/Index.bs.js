

import * as React from "react";
import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as App$ReasonMusicCtx from "./App.bs.js";
import * as Amplify$ReasonMusicCtx from "./aws/Amplify.bs.js";

function loglevel(param) {
  return window.LOGLEVEL;
}

var partial_arg = window;

function setLogLevel(param) {
  partial_arg.LOGLEVEL = param;
  return /* () */0;
}

Amplify$ReasonMusicCtx.configure(Amplify$ReasonMusicCtx.Config.awsConfig);

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonMusicCtx.make, { }), "root");

export {
  loglevel ,
  setLogLevel ,
  
}
/* partial_arg Not a pure module */
