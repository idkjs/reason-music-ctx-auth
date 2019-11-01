open AuthTypes;
type state = {user};
let initialState = {
  isLoggedIn: false,
  username: Js.Nullable.null,
  id: Js.Nullable.null,
  email: Js.Nullable.null,
};
let reducer = (_, action) =>
  switch (action) {
  | UserLoggedIn(userData) => userData
  | UserLoggedOut => 
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer,initialState);
  <UserContext.Provider value=(state, dispatch)>
    <Home />
  </UserContext.Provider>;
};