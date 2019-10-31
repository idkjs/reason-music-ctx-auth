

import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Caml_array from "bs-platform/lib/es6/caml_array.js";
import * as Caml_int32 from "bs-platform/lib/es6/caml_int32.js";
import * as MusicPlayer$ReasonMusicCtx from "./MusicPlayer.bs.js";

function useMusicPlayer(param) {
  var match = React.useContext(MusicPlayer$ReasonMusicCtx.musicPlayerContext);
  var dispatch = match[1];
  var state = match[0];
  var playing = state[/* playing */1];
  var trackList = state[/* tracks */0];
  var user = state[/* user */2];
  var renderSignIn = user ? "Play as song, " + (user[0] + "!") : "Please sign in";
  var isLoggedIn = user ? true : false;
  var currentTrackName = playing ? Caml_array.caml_array_get(state[/* tracks */0], playing[0])[/* name */0] : "Please choose a track to play";
  var pauseTrack = function (param) {
    return Curry._1(dispatch, /* PauseTrack */0);
  };
  var signIn = function (string) {
    return Curry._1(dispatch, /* UserLoggedIn */Block.__(1, [string]));
  };
  var signOut = function (param) {
    return Curry._1(dispatch, /* UserLoggedOut */1);
  };
  var playTrack = function (index) {
    if (playing) {
      var match = index === playing[0];
      if (match) {
        return Curry._1(dispatch, /* PauseTrack */0);
      } else {
        state[/* audioPlayer */3].pause();
        return Curry._1(dispatch, /* PlayTrack */Block.__(0, [index]));
      }
    } else {
      return Curry._1(dispatch, /* PlayTrack */Block.__(0, [index]));
    }
  };
  React.useEffect((function () {
          var match = state[/* playing */1];
          if (match) {
            state[/* audioPlayer */3].play();
          } else {
            state[/* audioPlayer */3].pause();
          }
          return ;
        }), /* array */[state[/* playing */1]]);
  var trackListLength = trackList.length;
  var playPreviousTrack = function (param) {
    if (playing) {
      return playTrack(Caml_int32.mod_(Caml_int32.mod_(playing[0] - 1 | 0, trackListLength) + trackListLength | 0, trackListLength));
    } else {
      return /* () */0;
    }
  };
  var playNextTrack = function (param) {
    if (playing) {
      return playTrack(Caml_int32.mod_(playing[0] + 1 | 0, trackListLength));
    } else {
      return /* () */0;
    }
  };
  return /* tuple */[
          playing,
          trackList,
          currentTrackName,
          pauseTrack,
          playTrack,
          playPreviousTrack,
          playNextTrack,
          isLoggedIn,
          user,
          signIn,
          signOut,
          renderSignIn
        ];
}

export {
  useMusicPlayer ,
  
}
/* react Not a pure module */
