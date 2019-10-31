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

type state = {
  tracks: musicTracks,
  playing,
  user,
  audioPlayer: JsAudio.audio,
};
