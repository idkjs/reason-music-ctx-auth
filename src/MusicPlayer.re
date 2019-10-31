[@bs.module "./bensound-goinghigher.mp3"]
external goinghigher: string = "default";
[@bs.module "./bensound-jazzyfrenchy.mp3"]
external jazzyfrenchy: string = "default";
[@bs.module "./bensound-summer.mp3"] external summer: string = "default";

let initialState: SharedTypes.state = {
  tracks: [|
    {name: "Benjamin Tissot - GoingHigher", file: goinghigher},
    {name: "Benjamin Tissot - JazzyRrenchy", file: jazzyfrenchy},
    {name: "Benjamin Tissot - Summer", file: summer},
  |],
  playing: NotPlaying,
  user: Anonymous,
  audioPlayer: JsAudio.(make("")),
};

type action =
  | PauseTrack // (A)
  | PlayTrack(int)
  | UserLoggedIn(string)
  | UserLoggedOut;

// when we pause a track, we need to transition to
// the `NotPlaying` state
//
let withPauseTrack = (state): SharedTypes.state => {
  ...state,
  playing: NotPlaying // (B)
};

// when we play a track, we need to transition to
// the `PlayingState` and add the payload of the
// track's index
//
let withPlayTrack = (state: SharedTypes.state, index) => {
  ...state,
  playing: Playing(index),
  audioPlayer: JsAudio.(make(state.tracks[index].file)),
};

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  // (A)
  | PauseTrack => withPauseTrack(state)
  | PlayTrack(index) => withPlayTrack(state, index)
  | UserLoggedIn(userName) => {...state, user: LoggedIn(userName)}
  | UserLoggedOut => {...state, user: Anonymous}
  };

let musicPlayerContext = React.createContext((initialState, ignore));
module MusicPlayerProvider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(musicPlayerContext);
};

[@react.component]
let make = (~children) => {
  let value = React.useReducer(reducer, initialState);
  <MusicPlayerProvider value> children </MusicPlayerProvider>;
};