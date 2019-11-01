

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Hub$ReasonMusicCtx from "./hub/Hub.bs.js";
import * as Auth$ReasonMusicCtx from "./aws/Auth.bs.js";
import * as Home$ReasonMusicCtx from "./auth/Home.bs.js";
import * as Logr$ReasonMusicCtx from "./hub/Logr.bs.js";
import * as AuthTypes$ReasonMusicCtx from "./auth/AuthTypes.bs.js";
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
  var checkUser = function (param) {
    Auth$ReasonMusicCtx.currentAuthenticatedUser.then((function (res) {
              var x = AuthTypes$ReasonMusicCtx.fromJs(res);
              var userData_001 = /* username */x[/* username */0];
              var userData_002 = /* id */x[/* attributes */1][/* sub */0];
              var userData_003 = /* email */x[/* attributes */1][/* email */2];
              var userData = /* record */[
                /* isLoggedIn */true,
                userData_001,
                userData_002,
                userData_003
              ];
              console.log("sign up success!");
              console.log(userData);
              Curry._1(dispatch, /* UserLoggedIn */[userData]);
              return Promise.resolve(/* () */0);
            })).catch((function (err) {
            console.log(err);
            var errMsg = "error signing up.." + String(err);
            console.log(errMsg);
            return Promise.resolve(/* () */0);
          }));
    return /* () */0;
  };
  var logger = Logr$ReasonMusicCtx.createLogger("UserProvider", /* Info */2, /* () */0);
  var listener = function (data) {
    console.log("listener_data_appre", data);
    Logr$ReasonMusicCtx.log(logger, /* Info */2, "listening for auth events...");
    var payload = data.payload;
    console.log("payload", payload.event);
    var $$event = payload.event;
    console.log("listener_data_event_appre", $$event);
    switch ($$event) {
      case "signIn" :
          console.log("signIn_event", payload);
          return /* () */0;
      case "signOut" :
          console.log("appre_logger_msg: user signed in", payload);
          return Curry._1(dispatch, /* UserLoggedOut */0);
      default:
        console.log("logger", data);
        return /* () */0;
    }
  };
  React.useEffect((function () {
          checkUser(/* () */0);
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
