const movies = [
  {
    id: 1,
    title: "Spiderman",
    genre: "Action",
    stock: 5,
    rate: 8,
    liked: false,
  },
  { id: 2, title: "Batman", genre: "Action", stock: 4, rate: 4, liked: false },
  {
    id: 3,
    title: "The Avengers",
    genre: "Action",
    stock: 3,
    rate: 9,
    liked: false,
  },
  {
    id: 4,
    title: "The Dark Knight",
    genre: "Action",
    stock: 2,
    rate: 7,
    liked: false,
  },
  {
    id: 5,
    title: "The Godfather",
    genre: "Drama",
    stock: 1,
    rate: 10,
    liked: false,
  },
  {
    id: 6,
    title: "The Godfather II",
    genre: "Drama",
    stock: 0,
    rate: 8,
    liked: false,
  },
  {
    id: 7,
    title: "The Godfather III",
    genre: "Drama",
    stock: 0,
    rate: 7,
    liked: false,
  },
  {
    id: 8,
    title: "The Shawshank Redemption",
    genre: "Drama",
    stock: 0,
    rate: 9,
  },
];

export const getMoviesFromDB = () => {
  // Usually we would get the movies from a database
  return movies;
};
