open ReactUtils;

[@react.component]
let make = () => {
  let (user, _) = UserContext.useUser();
  let isLoggedIn =
    switch (user) {
    | LoggedIn(_string) => true
    | Anonymous => false
    };
  <div className="section is-fullheignt">
    <div className="container">
      <div className="column is-6 is-offset-4">
        <h1 className="is-size-2 has-text-centered">
          {s("Reason Music Player")}
        </h1>
        <br />
        {!isLoggedIn
           ? <div>
               <span className="user-message">
                 {React.string("Sneaky, you are browsing anonymously!")}
                 <br />
                 {React.string("Sign in to see the track list.")}
               </span>
               <AuthControl />
             </div>
           : <div>
               <AuthControl />
               <MusicPlayer> <TrackList /> <PlayerControls /> </MusicPlayer>
             </div>}
      </div>
    </div>
  </div>;
  /* what it looks like if we don't uses `isLoggedIn` bool. Uncomment to see it render */
  //         {switch (user) {
  //          | Anonymous =>
  //            <div>
  //              <span className="user-message">
  //                {React.string("Sneaky, you are browsing anonymously!")}
  //                <br />
  //                {React.string("Sign in to see the track list.")}
  //              </span>
  //              <AuthControl />
  //            </div>
  // /* we dont care about the username here so we ignore it and just use the fact that it exists to render the LoggedIn variant */
  //          | LoggedIn(_userName) =>
  //            <div>
  //              <AuthControl />
  //              <MusicPlayer> <TrackList /> <PlayerControls /> </MusicPlayer>
  //            </div>
  //          }}
};