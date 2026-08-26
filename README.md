# Vibe Coding vs. Traditional Coding Experiment

This repository documents a small mixed-methods experiment comparing
Vibe Coding with Traditional Coding among university students.

## Experiment Overview

The study investigates the effect of Vibe Coding on programming performance
compared with Traditional Coding.

- **Design:** Between-subjects comparison
- **Participants:** 10 university students
  - Vibe Coding: V1–V5 (`n = 5`)
  - Traditional Coding: T2, T4, T5, T6, T10 (`n = 5`)
- **Tasks:** Three programming tasks evaluated on the Kattis platform
- **Time limit:** 120 minutes for the experimental session
- **Main outcomes:** Completion time, test-case performance, debugging activity,
  and raw NASA-TLX workload
- **Statistical test:** Two-sided Mann–Whitney U test, using the participant as
  the unit of analysis

## Files

- [`experiment_setup_and_results.md`](experiment_setup_and_results.md) —
  experimental procedure, anonymized data, calculations and statistical results.

## Important analysis note

The NASA-TLX subscale values reported in the final table are **arithmetic
group means**The NASA-TLX subscale values reported in the final table are arithmetic group means. They should not be interpreted or reported as medians.
For the overall participant-level NASA-TLX comparison, the six subscale scores were averaged within each participant first. The resulting five participant scores from each group were then used for the Mann–Whitney U test.
## Data Privacy
All participant identifiers are anonymized. No names or
other direct identifiers are included.
The participant codes are used only to link the experimental records with the corresponding code submissions.
## Repository Structure

```text
├── Traditional coding/
│   ├── Participant_01/
│   ├── Participant_02/
│   ├── Participant_03/
│   ├── Participant_04/
│   └── Participant_05/
│
├── Vibe coding/
│   ├── Participant_01/
│   ├── Participant_02/
│   ├── Participant_03/
