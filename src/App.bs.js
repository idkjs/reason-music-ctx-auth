

import * as React from "react";
import * as Header$ReasonMusicCtx from "./Header.bs.js";
import * as TrackList$ReasonMusicCtx from "./TrackList.bs.js";
import * as MusicPlayer$ReasonMusicCtx from "./MusicPlayer.bs.js";
import * as PlayerControls$ReasonMusicCtx from "./PlayerControls.bs.js";

function App(Props) {
  return React.createElement("div", {
              className: "section is-fullheignt"
            }, React.createElement("div", {
                  className: "container"
                }, React.createElement("div", {
                      className: "column is-6 is-offset-4"
                    }, React.createElement("h1", {
                          className: "is-size-2 has-text-centered"
                        }, "Reason Music Player"), React.createElement("br", undefined), React.createElement(MusicPlayer$ReasonMusicCtx.make, {
                          children: null
                        }, React.createElement(Header$ReasonMusicCtx.make, { }), React.createElement(TrackList$ReasonMusicCtx.make, { }), React.createElement(PlayerControls$ReasonMusicCtx.make, { })))));
}

var make = App;

export {
  make ,
  
}
/* react Not a pure module */
