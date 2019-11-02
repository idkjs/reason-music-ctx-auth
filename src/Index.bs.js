

import * as React from "react";
import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as App$ReasonMusicCtx from "./App.bs.js";
import * as Amplify$ReasonMusicCtx from "./aws/Amplify.bs.js";

function loglevel(param) {
  return window.LOG_LEVEL;
}

window.LOG_LEVEL = "DEBUG";

console.log("loglevel", window.LOG_LEVEL);

Amplify$ReasonMusicCtx.configure(Amplify$ReasonMusicCtx.Config.awsConfig);

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonMusicCtx.make, { }), "root");

var setLogLevel = /* () */0;

export {
  loglevel ,
  setLogLevel ,
  
}
/*  Not a pure module */
