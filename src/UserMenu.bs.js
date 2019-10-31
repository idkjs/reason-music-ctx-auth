

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as UseMusicPlayer$ReasonMusicCtx from "./useMusicPlayer.bs.js";

function UserMenu(Props) {
  var match = UseMusicPlayer$ReasonMusicCtx.useMusicPlayer(/* () */0);
  var signOut = match[10];
  var signIn = match[9];
  var user = match[8];
  var match$1 = React.useState((function () {
          return "";
        }));
  var setUserName = match$1[1];
  var userName = match$1[0];
  if (user) {
    return React.createElement("div", {
                className: "user-form"
              }, React.createElement("span", {
                    className: "logged-in"
                  }, "Logged in as: ", React.createElement("b", undefined, user[0])), React.createElement("button", {
                    onClick: (function (param) {
                        return Curry._1(signOut, /* () */0);
                      })
                  }, "Log out"));
  } else {
    return React.createElement("form", {
                className: "user-form",
                onSubmit: (function (e) {
                    e.preventDefault();
                    return Curry._1(signIn, userName);
                  })
              }, React.createElement("input", {
                    className: "login-input",
                    placeholder: "User name",
                    value: userName,
                    onChange: (function (e) {
                        var value = e.target.value;
                        return Curry._1(setUserName, (function (param) {
                                      return value;
                                    }));
                      })
                  }), React.createElement("button", {
                    type: "submit"
                  }, "Log in"));
  }
}

var make = UserMenu;

export {
  make ,
  
}
/* react Not a pure module */
