

import * as React from "react";
import * as Home$ReasonMusicCtx from "./auth/Home.bs.js";
import * as UserContext$ReasonMusicCtx from "./auth/UserContext.bs.js";

function reducer(param, action) {
  if (action) {
    return /* record */[/* user : LoggedIn */[action[0]]];
  } else {
    return /* record */[/* user : Anonymous */0];
  }
}

function App(Props) {
  var match = React.useReducer(reducer, /* record */[/* user : Anonymous */0]);
  return React.createElement(UserContext$ReasonMusicCtx.Provider.make, UserContext$ReasonMusicCtx.Provider.makeProps(/* tuple */[
                  match[0][/* user */0],
                  match[1]
                ], React.createElement(Home$ReasonMusicCtx.make, { }), /* () */0));
}

var make = App;

export {
  reducer ,
  make ,
  
}
/* react Not a pure module */
