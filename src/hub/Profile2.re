type attributes = {
  sub: int,
  email_verified: bool,
  email: string,
  phone_number: Js.Nullable.t(string),
};
type userInfo = {
  username: string,
  attributes,
};
let fromJsAttrs: Js.t('a) => attributes =
  attributes => {
    sub: attributes##sub,
    email_verified: attributes##email_verified,
    email: attributes##email,
    phone_number: Js.Nullable.return(attributes##phone_number),
  };
let fromJs: Js.t('a) => userInfo =
  data => {
    username: data##username,
    attributes: fromJsAttrs(data##attributes),
  };
external toString: 'a => string = "%identity";

[@react.component]
let make = () => {
  let (user, setUser) = React.useState(() => None);
  let checkUser = () => {
    Auth.currentUserPoolUser(~userPoolId=Amplify.Config.userPoolId)
    |> Js.Promise.then_(data => {
         let userInfo = {
           username: data##username,
           attributes: data##attributes,
         };
         setUser(_ => Some(userInfo));
         Js.log(data);
         Js.log2("userInfo: ", userInfo);
         Js.Promise.resolve(Belt.Result.Ok(data));
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         Js.Promise.resolve(Belt.Result.Error(error));
       })
    |> ignore;
  };

  let signOut = () => {
    Auth.signOut()
    |> Js.Promise.then_(data => {
         Js.log(data);
         Js.log2("userInfo: ", data);
         Js.Promise.resolve(Belt.Result.Ok(data));
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         Js.Promise.resolve(Belt.Result.Error(error));
       })
    |> ignore;
  };
  open Hub;
  let logger = str => Js.log(str);
  // let fromJs:

  let listener: Hub.cb =
    data => {
      Js.log2("listener_hubCallback", data);

      let payload = data->payloadGet;
      Js.log2("payload", payload->eventGet);

      let event = payload->eventGet;
      Js.log2("listener_hubCallback_event", event);
      switch (event) {
      | "signIn" => logger("profile_logger_msg: user signed in")
      | "signUp" => logger("profile_logger_msg: user signed up")

      | "signOut" => logger("profile_logger_msg: user signed out")

      | "signIn_failure" => logger("profile_logger_msg: user sign in failed")

      | "configured" =>
        logger("profile_logger_msg: the Auth module is configured")
      | _ => logger("unknown error")
      };
    };
  React.useEffect1(
    () => {
      checkUser();
      Hub.listen(Auth, listener);
      Some(() => Hub.remove(Auth, listener));
    },
    [||],
  );

  // let formType: FormTypes.formType = SignIn;
  let renderProfile =
    switch (user) {
    | Some(user) =>
      <div>
        <h1> "Profile"->React.string </h1>
        <h2> {"Username: " ++ user.username |> React.string} </h2>
        <h3> {"Email: " ++ user.attributes.email |> React.string} </h3>
        // <h4>{"Phone: " ++ user.phone_number|>React.string}</h4>
        <button onClick={_ => signOut()}>
          {"Sign Out" |> React.string}
        </button>
      </div>
    | None => <h1> "No User"->React.string </h1>
    };
  renderProfile;
};