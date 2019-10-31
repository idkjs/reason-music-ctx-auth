

import * as React from "react";
import * as Caml_array from "bs-platform/lib/es6/caml_array.js";
import * as BensoundSummerMp3 from "./bensound-summer.mp3";
import * as BensoundGoinghigherMp3 from "./bensound-goinghigher.mp3";
import * as BensoundJazzyfrenchyMp3 from "./bensound-jazzyfrenchy.mp3";

var goinghigher = BensoundGoinghigherMp3.default;

var jazzyfrenchy = BensoundJazzyfrenchyMp3.default;

var summer = BensoundSummerMp3.default;

var initialState_000 = /* tracks : array */[
  /* record */[
    /* name */"Benjamin Tissot - GoingHigher",
    /* file */goinghigher
  ],
  /* record */[
    /* name */"Benjamin Tissot - JazzyFrenchy",
    /* file */jazzyfrenchy
  ],
  /* record */[
    /* name */"Benjamin Tissot - Summer",
    /* file */summer
  ]
];

var initialState_002 = /* audioPlayer */new Audio("");

var initialState = /* record */[
  initialState_000,
  /* playing : NotPlaying */0,
  initialState_002
];

function withPauseTrack(state) {
  return /* record */[
          /* tracks */state[/* tracks */0],
          /* playing : NotPlaying */0,
          /* audioPlayer */state[/* audioPlayer */2]
        ];
}

function withPlayTrack(state, index) {
  return /* record */[
          /* tracks */state[/* tracks */0],
          /* playing : Playing */[index],
          /* audioPlayer */new Audio(Caml_array.caml_array_get(state[/* tracks */0], index)[/* file */1])
        ];
}

function reducer(state, action) {
  if (action) {
    return withPlayTrack(state, action[0]);
  } else {
    return withPauseTrack(state);
  }
}

var musicPlayerContext = React.createContext(/* tuple */[
      initialState,
      (function (prim) {
          return /* () */0;
        })
    ]);

function makeProps(value, children, param) {
  return {
          value: value,
          children: children
        };
}

var make = musicPlayerContext.Provider;

var MusicPlayerProvider = {
  makeProps: makeProps,
  make: make
};

function MusicPlayer(Props) {
  var children = Props.children;
  var value = React.useReducer(reducer, initialState);
  return React.createElement(make, makeProps(value, children, /* () */0));
}

var make$1 = MusicPlayer;

export {
  goinghigher ,
  jazzyfrenchy ,
  summer ,
  initialState ,
  withPauseTrack ,
  withPlayTrack ,
  reducer ,
  musicPlayerContext ,
  MusicPlayerProvider ,
  make$1 as make,
  
}
/* goinghigher Not a pure module */
