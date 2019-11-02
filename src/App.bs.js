

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Hub$ReasonMusicCtx from "./hub/Hub.bs.js";
import * as Home$ReasonMusicCtx from "./auth/Home.bs.js";
import * as Logr$ReasonMusicCtx from "./hub/Logr.bs.js";
import * as CognitoUser$ReasonMusicCtx from "./aws/CognitoUser.bs.js";
import * as UserContext$ReasonMusicCtx from "./auth/UserContext.bs.js";

function loglevel(param) {
  return window.LOGLEVEL;
}

var partial_arg = window;

function setLogLevel(param) {
  partial_arg.LOGLEVEL = param;
  return /* () */0;
}

function reducer(param, action) {
  if (action) {
    return /* record */[/* user : LoggedIn */[action[0]]];
  } else {
    return /* record */[/* user : Anonymous */0];
  }
}

function App(Props) {
  var match = React.useReducer(reducer, /* record */[/* user : Anonymous */0]);
  var dispatch = match[1];
  var logger = Logr$ReasonMusicCtx.createLogger("UserProvider", /* Info */2, /* () */0);
  var listener = function (data) {
    console.log("listener_data_appre", data);
    Logr$ReasonMusicCtx.log(logger, /* Info */2, "listening for auth events...");
    Logr$ReasonMusicCtx.logO(logger, /* Info */2, data.payload);
    logger.info("listening for auth events...");
    var payload = data.payload;
    console.log("appre_payload_appre", payload);
    var cognitoUserJs = payload.data;
    console.log("appre_payloadData_appre", cognitoUserJs);
    var $$event = payload.event;
    var cognitoUser = CognitoUser$ReasonMusicCtx.userResponsefromJs(cognitoUserJs);
    console.log("appre_cognitoUser_appre", cognitoUser);
    console.log("appre_cognitoUser_appre", cognitoUser[/* username */0]);
    console.log("appre_payload_event_appre", $$event);
    switch ($$event) {
      case "configured" :
          console.log("profile_msg: the Auth module is configured", data);
          return /* () */0;
      case "signIn" :
          console.log("appre_logr_signIn_event_data", data);
          var userData_001 = /* username */cognitoUser[/* username */0];
          var userData_002 = /* id */cognitoUser[/* attributes */8][/* sub */0];
          var userData_003 = /* email */cognitoUser[/* attributes */8][/* email */2];
          var userData = /* record */[
            /* isLoggedIn */true,
            userData_001,
            userData_002,
            userData_003
          ];
          console.log("userData signed up", userData);
          return Curry._1(dispatch, /* UserLoggedIn */[userData]);
      case "signIn_failure" :
          console.log("user sign in failed", data);
          return /* () */0;
      case "signOut" :
          console.log("appre_logger_msg: user signed in", payload);
          return Curry._1(dispatch, /* UserLoggedOut */0);
      case "signUp" :
          console.log("user signed up", data);
          return /* () */0;
      default:
        console.log("unknown error", data);
        return /* () */0;
    }
  };
  React.useEffect((function () {
          Hub$ReasonMusicCtx.listen(/* Auth */1, listener);
          return (function (param) {
                    return Hub$ReasonMusicCtx.remove(/* Auth */1, listener);
                  });
        }), /* array */[]);
  return React.createElement(UserContext$ReasonMusicCtx.Provider.make, UserContext$ReasonMusicCtx.Provider.makeProps(/* tuple */[
                  match[0][/* user */0],
                  dispatch
                ], React.createElement(Home$ReasonMusicCtx.make, { }), /* () */0));
}

var make = App;

export {
  loglevel ,
  setLogLevel ,
  reducer ,
  make ,
  
}
/* partial_arg Not a pure module */
