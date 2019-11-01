type userData = {
  isLoggedIn: bool,
  username: Js.Nullable.t(string),
  id: Js.Nullable.t(int),
  email: Js.Nullable.t(string),
};
type user =
  | Anonymous
  | LoggedIn(userData);
type userAction =
  | UserLoggedIn(userData)
  | UserLoggedOut;


// type action =
//     | SetState(user);
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