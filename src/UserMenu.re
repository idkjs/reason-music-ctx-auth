open ReactUtils;

[@react.component]
let make = () => {
  let (
    _playing,
    _trackList,
    _currentTrackName,
    _pauseTrack,
    _playTrack,
    _playPreviousTrack,
    _playNextTrack,
    _isLoggedIn,
    user,
    signIn,
    signOut,
    _renderSignIn,
  ) =
    UseMusicPlayer.useMusicPlayer();
  let (userName, setUserName) = React.useState(() => "");
  switch (user) {
  | Anonymous =>
    <form
      className="user-form"
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        signIn(userName);
      }}>
      <input
        className="login-input"
        placeholder="User name"
        value=userName
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          setUserName(_ => value);
        }}
      />
      <button type_="submit"> {s("Log in")} </button>
    </form>
  | LoggedIn(userName) =>
    <div className="user-form">
      <span className="logged-in">
        {s("Logged in as: ")}
        <b> {s(userName)} </b>
      </span>
      <button onClick={_ => signOut()}> {s("Log out")} </button>
    </div>
  };
};