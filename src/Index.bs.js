

import * as React from "react";
import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as App$ReasonMusicCtx from "./App.bs.js";
import * as Amplify$ReasonMusicCtx from "./aws/Amplify.bs.js";

Amplify$ReasonMusicCtx.configure(Amplify$ReasonMusicCtx.Config.awsConfig);

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonMusicCtx.make, { }), "root");

export {
  
}
/*  Not a pure module */
