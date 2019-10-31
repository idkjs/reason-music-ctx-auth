let initialState: SharedTypes.state = {
  tracks: [|
    {name: "Benjamin Tissot - Summer", file: "summer"},
    {name: "Benjamin Tissot - Ukulele", file: "ukulele"},
    {name: "Benjamin Tissot - Creative Minds", file: "creativeminds"},
  |],
  playing: NotPlaying,
  user: Anonymous,
};

type action =
  | DoSomething;

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | DoSomething => state
  };
// let musicPlayerContext = React.createContext((initialState, ignore));
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
  // let (state, dispatch) = React.useReducer(reducer, initialState);

  // <MusicPlayerProvider value=(state, dispatch)>
  //   children
  // </MusicPlayerProvider>;
  let value = React.useReducer(reducer, initialState);
  <MusicPlayerProvider value> children </MusicPlayerProvider>;
};