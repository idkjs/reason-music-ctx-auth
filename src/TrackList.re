open ReactUtils;

[@react.component]
// (A)
let make = () => {
  let (
    playing,
    trackList,
    _currentTrackName,
    _pauseTrack,
    playTrack,
    _playPreviousTrack,
    _playNextTrack,
    isLoggedIn,
    _user,
    _signIn,
    _signOut,
    renderSignIn,
  ) =
    UseMusicPlayer.useMusicPlayer();
  // let (userName, setUserName) = React.useState(() => "");
  let renderTrackList = () => {
    Array.mapi(
      // (C)
      (index, track: SharedTypes.musicTrack) =>
        // (D)
        <div className="box" key={index |> string_of_int}>
          // (E)

            <div className="columns is-vcentered">
              <button className="button" onClick={_ => playTrack(index)}>
                  {switch (playing) {
                   | Playing(idx) =>
                     idx === index
                       ? <i className="fas fa-pause" />
                       : <i className="fas fa-play" />
                   | NotPlaying => <i className="fas fa-play" />
                   }}
                </button>
              <div className="song-title column"> {s(track.name)} </div>
            </div>
          </div>,
      trackList,
    )
    |> React.array; // (H)
  };
  <> renderSignIn->s {isLoggedIn ? renderTrackList() : React.null} </>;
};