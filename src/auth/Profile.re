// type attributes = {
//   sub: int,
//   email_verified: bool,
//   email: string,
//   phone_number: Js.Nullable.t(string),
// };
// type userInfo = {
//   username: string,
//   attributes,
// };
// let fromJsAttrs: Js.t('a) => attributes =
//   attributes => {
//     sub: attributes##sub,
//     email_verified: attributes##email_verified,
//     email: attributes##email,
//     phone_number: Js.Nullable.return(attributes##phone_number),
//   };
// let fromJs: Js.t('a) => userInfo =
//   data => {
//     username: data##username,
//     attributes: fromJsAttrs(data##attributes),
//   };
// external toString: 'a => string = "%identity";

[@react.component]
let make = () => {
  let (user, dispatch) = UserContext.useUser();
  let isLoggedIn =
    switch (user) {
    | LoggedIn(user) =>
      <div>
        <h1> "Profile"->React.string </h1>
        <h2>
          {"Username: "
           ++ user.username
           |> React.string}
        </h2>
        // <h2>
        //   {"Username: "
        //    ++ Js.Nullable.toOption(user.username)
        //       ->Belt.Option.getWithDefault("")
        //    |> React.string}
        // </h2>
        <h3>
          {"Email: "
           ++ user.email
           |> React.string}
        </h3>
        // <h3>
        //   {"Email: "
        //    ++ Js.Nullable.toOption(user.email)
        //       ->Belt.Option.getWithDefault("")
        //    |> React.string}
        // </h3>
        // <h4>{"Phone: " ++ user.phone_number|>React.string}</h4>
        <button onClick={_ => dispatch(UserLoggedOut)}>
          {"Sign Out" |> React.string}
        </button>
      </div>
    | Anonymous => <div> <h1> "No User"->React.string </h1> </div>
    };

  isLoggedIn;
};