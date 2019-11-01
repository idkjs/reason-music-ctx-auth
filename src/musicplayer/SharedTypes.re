type musicTrack = {
  name: string,
  file: string,
};

type musicTracks = array(musicTrack);

type playing =
  | Playing(int)
  | NotPlaying;
type user =
  | Anonymous
  | LoggedIn(string);
type userAction =
  | UserLoggedIn(string)
  | UserLoggedOut;
type state = {
  tracks: musicTracks,
  playing,
  audioPlayer: JsAudio.audio,
};
