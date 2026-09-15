import { render, screen } from "@testing-library/react";
import { MemoryRouter } from "react-router-dom";
import { DemoProvider } from "../../app/DemoProvider";
import { BuildProofPage } from "./BuildProofPage";

it("connects JOCKY source to measured build artifacts", async () => {
  render(
    <MemoryRouter>
      <DemoProvider><BuildProofPage /></DemoProvider>
    </MemoryRouter>,
  );

  expect(await screen.findByRole("heading", { name: "JOCKY build proof" })).toBeVisible();
  expect(screen.getByText("Lexer + parser")).toBeVisible();
  expect(screen.getByText("LLVM IR")).toBeVisible();
  expect(screen.getByText(/31bc56ed1f21a961/)).toBeVisible();
  expect(screen.getByText(/ab6dad8d37d4eb82/)).toBeVisible();
  expect(screen.getByText("Checked-in evaluation sample")).toBeVisible();
  expect(screen.queryByText(/undetectable|invisible to antivirus/i)).not.toBeInTheDocument();
});
