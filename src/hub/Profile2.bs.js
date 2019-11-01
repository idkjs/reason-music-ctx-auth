

import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as AwsAmplify from "aws-amplify";
import * as Hub$ReasonMusicCtx from "./Hub.bs.js";
import * as Auth$ReasonMusicCtx from "../aws/Auth.bs.js";
import * as Amplify$ReasonMusicCtx from "../aws/Amplify.bs.js";

function fromJsAttrs(attributes) {
  return /* record */[
          /* sub */attributes.sub,
          /* email_verified */attributes.email_verified,
          /* email */attributes.email,
          /* phone_number */attributes.phone_number
        ];
}

function fromJs(data) {
  return /* record */[
          /* username */data.username,
          /* attributes */fromJsAttrs(data.attributes)
        ];
}

function Profile2(Props) {
  var match = React.useState((function () {
          return ;
        }));
  var setUser = match[1];
  var user = match[0];
  var checkUser = function (param) {
    Auth$ReasonMusicCtx.currentUserPoolUser(Amplify$ReasonMusicCtx.Config.userPoolId).then((function (data) {
              var userInfo_000 = /* username */data.username;
              var userInfo_001 = /* attributes */data.attributes;
              var userInfo = /* record */[
                userInfo_000,
                userInfo_001
              ];
              Curry._1(setUser, (function (param) {
                      return userInfo;
                    }));
              console.log(data);
              console.log("userInfo: ", userInfo);
              return Promise.resolve(/* Ok */Block.__(0, [data]));
            })).catch((function (error) {
            console.log("error", error);
            return Promise.resolve(/* Error */Block.__(1, [error]));
          }));
    return /* () */0;
  };
  var listener = function (data) {
    console.log("listener_hubCallback", data);
    var payload = data.payload;
    console.log("payload", payload.event);
    var $$event = payload.event;
    console.log("listener_hubCallback_event", $$event);
    switch ($$event) {
      case "configured" :
          console.log("profile_logger_msg: the Auth module is configured");
          return /* () */0;
      case "signIn" :
          console.log("profile_logger_msg: user signed in");
          return /* () */0;
      case "signIn_failure" :
          console.log("profile_logger_msg: user sign in failed");
          return /* () */0;
      case "signOut" :
          console.log("profile_logger_msg: user signed out");
          return /* () */0;
      case "signUp" :
          console.log("profile_logger_msg: user signed up");
          return /* () */0;
      default:
        console.log("unknown error");
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
  if (user !== undefined) {
    var user$1 = user;
    return React.createElement("div", undefined, React.createElement("h1", undefined, "Profile"), React.createElement("h2", undefined, "Username: " + user$1[/* username */0]), React.createElement("h3", undefined, "Email: " + user$1[/* attributes */1][/* email */2]), React.createElement("button", {
                    onClick: (function (param) {
                        AwsAmplify.Auth.signOut().then((function (data) {
                                  console.log(data);
                                  console.log("userInfo: ", data);
                                  return Promise.resolve(/* Ok */Block.__(0, [data]));
                                })).catch((function (error) {
                                console.log("error", error);
                                return Promise.resolve(/* Error */Block.__(1, [error]));
                              }));
                        return /* () */0;
                      })
                  }, "Sign Out"));
  } else {
    return React.createElement("h1", undefined, "No User");
  }
}

var make = Profile2;

export {
  fromJsAttrs ,
  fromJs ,
  make ,
  
}
/* react Not a pure module */
