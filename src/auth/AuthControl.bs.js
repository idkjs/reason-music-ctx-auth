

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as UserContext$ReasonMusicCtx from "./UserContext.bs.js";

function AuthControl(Props) {
  var match = UserContext$ReasonMusicCtx.useUser(/* () */0);
  var dispatch = match[1];
  var user = match[0];
  var match$1 = React.useState((function () {
          return "musicLover";
        }));
  var setUserName = match$1[1];
  var userName = match$1[0];
  if (user) {
    return React.createElement("div", {
                className: "user-form"
              }, React.createElement("span", {
                    className: "logged-in"
                  }, "Logged in as: ", React.createElement("b", undefined, user[0])), React.createElement("div", {
                    className: "control"
                  }, React.createElement("button", {
                        className: "button is-link",
                        onClick: (function (param) {
                            return Curry._1(dispatch, /* UserLoggedOut */0);
                          })
                      }, "Log Out")));
  } else {
    return React.createElement("form", {
                className: "user-form",
                onSubmit: (function (e) {
                    e.preventDefault();
                    return Curry._1(dispatch, /* UserLoggedIn */[userName]);
                  })
              }, React.createElement("div", {
                    className: "field"
                  }, React.createElement("label", {
                        className: "label"
                      }, "Username"), React.createElement("div", {
                        className: "control has-icons-left has-icons-right"
                      }, React.createElement("input", {
                            className: "input is-success",
                            placeholder: "User name",
                            type: "text",
                            value: userName,
                            onChange: (function (e) {
                                var value = e.target.value;
                                return Curry._1(setUserName, (function (param) {
                                              return value;
                                            }));
                              })
                          }), React.createElement("span", {
                            className: "icon is-small is-left"
                          }, React.createElement("i", {
                                className: "fas fa-user"
                              })), React.createElement("span", {
                            className: "icon is-small is-right"
                          }, React.createElement("i", {
                                className: "fas fa-check"
                              }))), React.createElement("p", {
                        className: "help is-success"
                      }, "This username is available")), React.createElement("div", {
                    className: "control"
                  }, React.createElement("button", {
                        className: "button is-link",
                        type: "submit"
                      }, "Log in")));
  }
}

var make = AuthControl;

export {
  make ,
  
}
/* react Not a pure module */
