import React from "react";
import "./dataTable.css";
import FavoriteBorderIcon from "@mui/icons-material/FavoriteBorder";
import FavoriteIcon from "@mui/icons-material/Favorite";

export const DataTable = ({ moviesArr, handleLike, handleDelete }) => {
  return (
    <table className="table table-striped">
      <thead>
        <tr>
          <th scope="col">Title</th>
          <th scope="col">Genre</th>
          <th scope="col">Stock</th>
          <th scope="col">Rate</th>
          <th scope="col">Favorites</th>
          <th scope="col"></th>
        </tr>
      </thead>
      <tbody>
        {moviesArr &&
          moviesArr.map((movie) => {
            return (
              <tr>
                <td>{movie.title}</td>
                <td>{movie.genre}</td>
                <td>{movie.stock}</td>
                <td>{movie.rate}</td>
                <td>
                  {movie.liked ? (
                    <div
                      onClick={() => {
                        handleLike(movie.id, false);
                      }}
                    >
                      <FavoriteIcon />
                    </div>
                  ) : (
                    <div
                      onClick={() => {
                        handleLike(movie.id, true);
                      }}
                    >
                      <FavoriteBorderIcon />
                    </div>
                  )}
                </td>

                <td>
                  <button
                    className="btn btn-danger btn-sm"
                    onClick={() => {
                      handleDelete(movie.id);
                    }}
                  >
                    Delete
                  </button>
                </td>
              </tr>
            );
          })}
      </tbody>
    </table>
  );
};
