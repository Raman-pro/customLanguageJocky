import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "@fontsource-variable/manrope";
import "@fontsource-variable/jetbrains-mono";
import "./styles/tokens.css";
import "./styles/global.css";
import { App } from "./app/App";

const root = document.getElementById("root");

if (!root) throw new Error("Application root was not found");

createRoot(root).render(
  <StrictMode>
    <App />
  </StrictMode>,
);
