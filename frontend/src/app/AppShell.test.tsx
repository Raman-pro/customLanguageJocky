import { render, screen } from "@testing-library/react";
import { MemoryRouter } from "react-router-dom";
import { AppShell } from "./AppShell";
import { DemoProvider } from "./DemoProvider";

it("exposes primary destinations and the demo boundary", () => {
  render(
    <MemoryRouter>
      <DemoProvider><AppShell><div>Route content</div></AppShell></DemoProvider>
    </MemoryRouter>,
  );

  expect(screen.getByRole("navigation", { name: /primary/i })).toBeVisible();
  expect(screen.getByRole("link", { name: /fleet/i })).toBeVisible();
  expect(screen.getByRole("link", { name: /investigation/i })).toBeVisible();
  expect(screen.getByRole("link", { name: /build proof/i })).toBeVisible();
  expect(screen.getByText("Demo dataset")).toBeVisible();
  expect(screen.getByText("Route content")).toBeVisible();
});
