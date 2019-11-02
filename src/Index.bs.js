

import * as React from "react";
import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as App$ReasonMusicCtx from "./App.bs.js";
import * as Amplify$ReasonMusicCtx from "./aws/Amplify.bs.js";

function loglevel(param) {
  return window.LOG_LEVEL;
}

Amplify$ReasonMusicCtx.configure(Amplify$ReasonMusicCtx.Config.awsConfig);

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonMusicCtx.make, { }), "root");

export {
  loglevel ,
  
}
/*  Not a pure module */
