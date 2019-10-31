

import * as React from "react";

var initialState_000 = /* tracks : array */[
  /* record */[
    /* name */"Benjamin Tissot - Summer",
    /* file */"summer"
  ],
  /* record */[
    /* name */"Benjamin Tissot - Ukulele",
    /* file */"ukulele"
  ],
  /* record */[
    /* name */"Benjamin Tissot - Creative Minds",
    /* file */"creativeminds"
  ]
];

var initialState = /* record */[
  initialState_000,
  /* playing : NotPlaying */0,
  /* user : Anonymous */0
];

function reducer(state, action) {
  return state;
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
  initialState ,
  reducer ,
  musicPlayerContext ,
  MusicPlayerProvider ,
  make$1 as make,
  
}
/* musicPlayerContext Not a pure module */
