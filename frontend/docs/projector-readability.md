# Projector readability review

## Palette comparison

Compared three palettes on the same fleet dashboard layout. Each was reviewed
normally and with a 20% white overlay to approximate loss of contrast under
ambient light. This is a visual stress check, not a calibration of the actual
presentation projector.

| Palette | Primary text / panel | Secondary text / panel | Button text / fill | Boundary / panel |
| --- | ---: | ---: | ---: | ---: |
| Slate / blue — selected | 16.33:1 | 9.63:1 | 8.63:1 | 4.71:1 |
| Ivory / rust | 15.76:1 | 8.94:1 | 6.90:1 | 5.28:1 |
| Navy / amber | 14.01:1 | 11.02:1 | 10.86:1 | 5.38:1 |

Ratios use the specified sRGB colors without the simulated overlay. They describe
these color pairs, not whole-application accessibility certification.

Slate / blue was selected for distinct white content panels against the slate
canvas, strong navy text, and clear blue actions. Ivory / rust is the closest
alternative to the original editorial reference. Navy / amber remains readable
in the experiment, but its dark surfaces appear flatter with simulated washout.

## Applied changes

- Enclosed content panels with 2px outlines and contrasting header backgrounds.
- White metric panels with visible individual boundaries.
- 16–18px primary operational text and 14–15px supporting text on desktop.
- Smaller display headings to give the useful dashboard content more space.
- Sentence-case, uncondensed section headings and stronger label weights.
- Filled active navigation, outlined status labels with text, and larger controls.
- Alternating table rows and stronger column headers.
- Responsive evidence records and wrapping source paths at narrow widths.
- Source panel secondary labels moved to the shared high-contrast text token.

The rendered text colors were inspected on all four primary screens. Final
projector brightness and room conditions should be assessed at the venue.
