

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as UseMusicPlayer$ReasonMusicCtx from "./useMusicPlayer.bs.js";

function PlayerControls(Props) {
  var match = UseMusicPlayer$ReasonMusicCtx.useMusicPlayer(/* () */0);
  var pauseTrack = match[3];
  var playing = match[0];
  return React.createElement(React.Fragment, undefined, React.createElement("div", {
                  className: "box controls has-background-grey-dark"
                }, React.createElement("div", {
                      className: "current-track has-text-light"
                    }, React.createElement("marquee", undefined, match[2])), React.createElement("div", {
                      className: "buttons is-centered"
                    }, React.createElement("button", {
                          className: "button has-text-light has-background-grey-dark",
                          disabled: playing ? false : true,
                          onClick: match[5]
                        }, React.createElement("i", {
                              className: "fas fa-step-backward"
                            })), React.createElement("button", {
                          className: "button has-text-light has-background-grey-dark",
                          disabled: playing ? false : true,
                          onClick: (function (param) {
                              return Curry._1(pauseTrack, /* () */0);
                            })
                        }, playing ? React.createElement("i", {
                                className: "fas fa-pause"
                              }) : React.createElement("i", {
                                className: "fas fa-play"
                              })), React.createElement("button", {
                          className: "button has-text-light has-background-grey-dark",
                          disabled: playing ? false : true,
                          onClick: match[6]
                        }, React.createElement("i", {
                              className: "fas fa-step-forward"
                            })))));
}

var make = PlayerControls;

export {
  make ,
  
}
/* react Not a pure module */
