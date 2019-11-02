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
