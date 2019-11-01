

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Auth$ReasonMusicCtx from "../aws/Auth.bs.js";
import * as AuthTypes$ReasonMusicCtx from "./AuthTypes.bs.js";
import * as UserContext$ReasonMusicCtx from "./UserContext.bs.js";

function AuthControl(Props) {
  var match = UserContext$ReasonMusicCtx.useUser(/* () */0);
  var dispatch = match[1];
  var user = match[0];
  var match$1 = React.useState((function () {
          return "musicLover";
        }));
  var setUsername = match$1[1];
  var username = match$1[0];
  var match$2 = React.useState((function () {
          return "";
        }));
  var setPassword = match$2[1];
  var password = match$2[0];
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
                    Auth$ReasonMusicCtx.signIn(username, password).then((function (res) {
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
                            value: username,
                            onChange: (function (e) {
                                var value = e.target.value;
                                return Curry._1(setUsername, (function (param) {
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
                    className: "field"
                  }, React.createElement("label", {
                        className: "label"
                      }, "Password"), React.createElement("div", {
                        className: "control has-icons-left has-icons-right"
                      }, React.createElement("input", {
                            className: "input is-success",
                            placeholder: "Password",
                            type: "text",
                            value: password,
                            onChange: (function (e) {
                                var value = e.target.value;
                                return Curry._1(setPassword, (function (param) {
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
                              })))), React.createElement("div", {
                    className: "control"
                  }, React.createElement("button", {
                        className: "button is-link",
                        type: "submit"
                      }, "Log in")), React.createElement("div", {
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
