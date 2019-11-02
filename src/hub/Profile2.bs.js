

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as UserContext$ReasonMusicCtx from "../auth/UserContext.bs.js";

function Profile2(Props) {
  var match = UserContext$ReasonMusicCtx.useUser(/* () */0);
  var dispatch = match[1];
  var user = match[0];
  if (user) {
    var user$1 = user[0];
    return React.createElement("div", undefined, React.createElement("h1", undefined, "Profile"), React.createElement("h2", undefined, "Username: " + user$1[/* username */1]), React.createElement("h3", undefined, "Email: " + user$1[/* email */3]), React.createElement("button", {
                    onClick: (function (param) {
                        return Curry._1(dispatch, /* UserLoggedOut */0);
                      })
                  }, "Sign Out"));
  } else {
    return React.createElement("div", undefined, React.createElement("h1", undefined, "No User"));
  }
}

var make = Profile2;

export {
  make ,
  
}
/* react Not a pure module */
