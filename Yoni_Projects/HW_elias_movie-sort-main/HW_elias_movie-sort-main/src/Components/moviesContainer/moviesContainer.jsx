import React from "react";
import { DataTable } from "../dataTable/dataTable";
import { getMoviesFromDB } from "../../../services/moviesServices";
import { useState } from "react";
import { FilterTableList } from "../filterTableList/filterTableList";
import "./moviesContainer.css";

const sortByTitle = (a, b) => {
  if (a.title < b.title) {
    return -1;
  }
  if (a.title > b.title) {
    return 1;
  }
  return 0;
};

let moviesFromDB = getMoviesFromDB().sort((a, b) => sortByTitle(a, b));
console.log(moviesFromDB);

export const MoviesContainer = (props) => {
  const [moviesList, setMovies] = useState(moviesFromDB);

  const [filter, setFilter] = useState("All");

  const handleFilter = (filter) => {
    setFilter(filter);
    if (filter === "All") {
      setMovies(moviesFromDB);
    } else {
      setMovies(moviesFromDB.filter((movie) => movie.genre === filter));
    }
  };

  const handleLike = (id, isLike) => {
    let movie = moviesList.find((m) => m.id === id);
    if (movie) {
      movie.liked = isLike;
    }

    // Optional sorting
    // let moviesNotEdited = moviesList.filter((m) => m.id !== id);
    // let moviesEdited = [...moviesNotEdited, movie].sort((a, b) =>
    //   sortByTitle(a, b)
    // );

    setMovies([...moviesList]);
  };

  const handleDelete = (id) => {
    let moviesNotDeleted = moviesList.filter((m) => m.id !== id);

    // Optional sorting
    //moviesNotDeleted = moviesNotDeleted.sort((a, b) => sortByTitle(a, b));

    setMovies(moviesNotDeleted);
  };
  return (
    <div className="moviesContainer">
      <div>
        <h1 className="listTitle"> Showing {moviesList.length} movies </h1>
      </div>
      <div className="movieList">
        <FilterTableList handleFilter={handleFilter} filter={filter} />
        <DataTable
          moviesArr={moviesList}
          handleLike={handleLike}
          handleDelete={handleDelete}
        ></DataTable>
      </div>
    </div>
  );
};
