// type userData = {
//   isLoggedIn: bool,
//   username: Js.Nullable.t(string),
//   id: Js.Nullable.t(int),
//   email: Js.Nullable.t(string),
// };
type userData = {
  isLoggedIn: bool,
  username: string,
  id: int,
  email: string,
};
type user =
  | Anonymous
  | LoggedIn(userData);
type userAction =
  | UserLoggedIn(userData)
  | UserLoggedOut;

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
// let isLoggedIn = bool => bool;
// let cog2auth: CognitoUser.userResponse => userData =
//   data => {
//     isLoggedIn: data.isLoggedIn,
//     username: Js.Nullable.return(data.username),
//     id: Js.Nullable.return(data.attributes.sub),
//     email: Js.Nullable.return(data.attributes.email),
//   };