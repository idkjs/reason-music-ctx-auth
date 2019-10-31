let useMusicPlayer = () => {
  // here we'll load our Context
  // it's the same as in JavaScript
  //
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let playing = state.playing;

  let trackList = state.tracks;
  let user = state.user;
  // find the current track name
  // we can pattern-match on our state
  // if we are in the state of `Playing`, then find the name of the
  // index of the tracks Array
  // if we don't play anything, we can't have a name, so we'll use
  // a placeholder string
  // ReasonML can infer types, so we don't have to tell the program
  // that the `currentTrackName` is a string
  //
  let renderSignIn =
    switch (user) {
    | LoggedIn(string) => "Play as song, " ++ string ++ "!"
    | Anonymous => "Please sign in"
    };
  let isLoggedIn =
    switch (user) {
    | LoggedIn(_string) => true
    | Anonymous => false
    };
  let currentTrackName =
    switch (playing) {
    | Playing(idx) => state.tracks[idx].name
    | NotPlaying => "Please choose a track to play"
    };

  // this function dispatches to `MusicPlayer` with the
  // `PauseTrack` action we defined earlier
  //
  let pauseTrack = () => MusicPlayer.PauseTrack |> dispatch;
  let signIn = string => MusicPlayer.UserLoggedIn(string) |> dispatch;
  let signOut = () => MusicPlayer.UserLoggedOut |> dispatch;
  // here we dispatch to the `PlayTrack(index)` action we defined
  // in `src/MusicPlayer.re`
  //
  let playTrack = index =>
    switch (playing) {
    | Playing(idx) =>
      index === idx
        ? pauseTrack()
        : {
          JsAudio.(state.audioPlayer |> pause); // * new *
          MusicPlayer.PlayTrack(index) |> dispatch;
        }
    | NotPlaying => MusicPlayer.PlayTrack(index) |> dispatch
    };
React.useEffect1(
  () => {
    switch (state.playing) {
    | Playing(_idx) => JsAudio.(state.audioPlayer |> play)
    | NotPlaying => JsAudio.(state.audioPlayer |> pause)
    };
    None;
  },
  [|state.playing|],
);
  let trackListLength = Array.length(trackList);

  let playPreviousTrack = _ =>
    switch (playing) {
    | Playing(idx) =>
      ((idx - 1) mod trackListLength + trackListLength)
      mod trackListLength
      |> playTrack
    | NotPlaying => ()
    };

  let playNextTrack = _ =>
    switch (playing) {
    | Playing(idx) => (idx + 1) mod trackListLength |> playTrack
    | NotPlaying => ()
    };

  (
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
    renderSignIn,
  );
};