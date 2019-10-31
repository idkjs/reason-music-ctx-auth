open AuthTypes;
type state = {user};

let reducer = (_, action) =>
  switch (action) {
  | UserLoggedIn(userName) => {user: LoggedIn(userName)}
  | UserLoggedOut => {user: Anonymous}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, {user: Anonymous});
  <UserContext.Provider value=(state.user, dispatch)>
    <Home />
  </UserContext.Provider>;
};
