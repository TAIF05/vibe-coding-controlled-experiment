# Experiment Setup and Results

## 1. Study objective

The study compares two approaches to completing programming tasks:

1. **Vibe Coding:** participants used GitHub Copilot and intent-oriented
   prompts. Participants did not manually edit the generated code; corrections
   were made by revising prompts or providing error messages to the tool.
2. **Traditional Coding:** participants wrote and debugged the code manually
   without using an AI code-generation tool.

The study uses a mixed-methods design. Quantitative measures were collected
during task completion, and participant reflections and workload ratings were
collected after the tasks.

## 2. Participants and grouping

| Group | Participant codes | n |
|---|---|---:|
| Vibe Coding | V1, V2, V3, V4, V5 | 5 |
| Traditional Coding | T2, T4, T5, T6, T10 | 5 |

Participants were university students in their third or fourth year with
different levels of prior familiarity with AI tools.

## 3. Experimental tasks and procedure

The participants completed programming tasks on the Kattis platform:

| Task | Problem |
|---|---:|---:|---:|
| Task 1 | Smallest Calculated Value |
| Task 2 | Who Goes There? | 
| Task 3 | In-place Sorting | 
The same overall session limit of **120 minutes** was used for all participants.
The following information was recorded:

- total completion time for each task;
- number and type of observed errors;
- number of debugging attempts;
- debugging time;
- whether the final code compiled successfully;
- number of passed test cases and runtime;
- NASA-TLX workload ratings.

Because the Traditional Coding group did not reach Task 3 within the session,
Task 3 is reported descriptively for the Vibe Coding group only and is not
included in a between-group Mann–Whitney test.

## 4. Operational definitions

- **Completion time:** minutes from starting a task until the participant
  submitted the final solution or the available time ended.
- **Debugging attempt:** one recorded attempt to correct an observed error.
- **Debugging time:** minutes spent addressing errors for that task.
- **Accuracy:** proportion of the task's test cases passed.
- **NASA-TLX score:** the arithmetic mean of six raw, unweighted subscales:
  Mental Demand, Physical Demand, Temporal Demand, Perceived Performance,
  Effort, and Frustration. Ratings range from 1 to 7.

## 5. Raw performance data

### 5.1 Task 1

| Participant | Group | Time (min) | Prompts | Error type | Debug attempts | Debug time (min) | Compiled? | Tests passed |
|---|---|---:|---:|---|---:|---:|:---:|---:|
| V1 | Vibe | 25 | 2 | Logical | 3 | 21 | Yes | 34/34 |
| V2 | Vibe | 18 | 5 | Syntax | 1 | 11 | Yes | 34/34 |
| V3 | Vibe | 22 | 1 | None | 0 | 0 | Yes | 34/34 |
| V4 | Vibe | 4 | 1 | None | 0 | 0 | Yes | 34/34 |
| V5 | Vibe | 8 | 1 | None | 0 | 0 | Yes | 34/34 |
| T2 | Traditional | 27 | — | None | 0 | 0 | Yes | 34/34 |
| T4 | Traditional | 36 | — | Logical | 1 | 13 | Yes | 34/34 |
| T5 | Traditional | 35 | — | None | 0 | 0 | Yes | 34/34 |
| T6 | Traditional | 41 | — | Logical | 2 | 22 | No | 22/34 |
| T10 | Traditional | 30 | — | None | 0 | 0 | Yes | 34/34 |

### 5.2 Task 2

| Participant | Group | Time (min) | Prompts | Error type | Debug attempts | Debug time (min) | Compiled? | Tests passed |
|---|---|---:|---:|---|---:|---:|:---:|---:|
| V1 | Vibe | 3 | 1 | None | 0 | 0 | Yes | 19/19 |
| V2 | Vibe | 11 | 4 | Logical | 3 | 6 | Yes | 19/19 |
| V3 | Vibe | 19 | 1 | None | 0 | 0 | Yes | 19/19 |
| V4 | Vibe | 2 | 1 | None | 0 | 0 | Yes | 19/19 |
| V5 | Vibe | 10 | 1 | None | 0 | 0 | Yes | 19/19 |
| T2 | Traditional | 43 | — | Logical | 2 | 25 | Yes | 19/19 |
| T4 | Traditional | 49 | — | None | 0 | 0 | Yes | 19/19 |
| T5 | Traditional | 30 | — | Syntax | 2 | 5 | Yes | 19/19 |
| T6 | Traditional | 21 | — | None | 0 | 0 | Yes | 19/19 |
| T10 | Traditional | 50 | — | None | 0 | 0 | Yes | 19/19 |

### 5.3 Task 3

The Traditional Coding participants did not reach Task 3 during the available
session time. The Vibe Coding results were:

| Participant | Group | Time (min) | Prompts | Error type | Debug attempts | Debug time (min) | Compiled? | Tests passed |
|---|---|---:|---:|---|---:|---:|:---:|---:|
| V1 | Vibe | 30 | 4 | Logical | 5 | 23 | No | 4/24 |
| V2 | Vibe | 9 | 2 | None | 0 | 0 | Yes | 24/24 |
| V3 | Vibe | 39 | 6 | Syntax | 1 | 4 | Yes | 24/24 |
| V4 | Vibe | 35 | 5 | Logical | 6 | 31 | No | 18/24 |
| V5 | Vibe | 12 | 1 | None | 0 | 0 | Yes | 24/24 |

Three of the five Vibe Coding participants passed all Task 3 test cases. The other two passed 4/24 and 18/24 cases.

## 6. NASA-TLX data

The following are the confirmed participant-level ratings used for the
descriptive group summaries. Each value is on a 1–7 scale.

| Participant | Group | Mental | Physical | Time pressure | Perceived performance | Effort | Frustration |
|---|---|---:|---:|---:|---:|---:|---:|
| T2 | Traditional | 2 | 1 | 1 | 7 | 1 | 1 |
| T4 | Traditional | 5 | 3 | 6 | 4 | 4 | 4 |
| T6 | Traditional | 6 | 4 | 5 | 3 | 5 | 2 |
| T5 | Traditional | 4 | 3 | 3 | 4 | 4 | 2 |
| T10 | Traditional | 5 | 5 | 3 | 6 | 6 | 2 |
| V1 | Vibe | 5 | 6 | 3 | 4 | 4 | 3 |
| V2 | Vibe | 4 | 2 | 3 | 3 | 2 | 2 |
| V3 | Vibe | 2 | 1 | 3 | 4 | 5 | 1 |
| V4 | Vibe | 4 | 3 | 3 | 4 | 4 | 2 |
| V5 | Vibe | 2 | 2 | 2 | 2 | 2 | 2 |

## 7. Statistical analysis and results

The Mann–Whitney U test was selected because the groups are independent, the
sample is small (`n = 5` per group), and the test does not require normally
distributed data. Unless otherwise stated, results below use a two-sided test
with `alpha = 0.05`.

### 7.1 Coding Speed(Completion time)

| Outcome | Vibe values | Traditional values | Vibe median | Traditional median | U | p-value | Result |
|---|---|---|---:|---:|---:|---:|---|
| Task 1 time (min) | 25, 18, 22, 4, 8 | 27, 36, 35, 41, 30 | 18 | 35 | 0 | 0.008 | Significant |
| Task 2 time (min) | 3, 11, 19, 2, 10 | 43, 49, 30, 21, 50 | 10 | 43 | 0 | 0.008 | Significant |

For both tasks, `U = 0` means that every Vibe Coding participant completed the
task faster than every Traditional Coding participant. The p-value is below
0.05, so the observed time difference is statistically significant in this
sample.

### 7.2 Debugging attempts and debugging time

| Outcome | Vibe values | Traditional values | Vibe median | Traditional median | U | 
|---|---|---|---:|---:|---:|
| Debug attempts — Task 1 | 3, 1, 0, 0, 0 | 0, 1, 0, 2, 0 | 0 | 0 | 12 |
| Debug attempts — Task 2 | 0, 3, 0, 0, 0 | 2, 0, 2, 0, 0 | 0 | 0 | 11 |
| Debug time — Task 1 (min) | 21, 11, 0, 0, 0 | 0, 13, 0, 22, 0 | 0 | 0 | 11.5 |
| Debug time — Task 2 (min) | 0, 6, 0, 0, 0 | 25, 0, 5, 0, 0 | 0 | 0 | 10 |

The medians are zero in both groups for every debugging outcome. Therefore,
the data do not provide evidence of a statistically significant group
difference in debugging attempts or debugging time. The large number of tied
zero values also limits the ability of a rank-based test to distinguish the
groups.

For these tied outcomes, the exact p-value depends on how the calculator
handles ties and continuity correction. The reported conclusion remains
`p > 0.05` for each comparison.
## 9. Calculations the U and p value

### 9.1 Using the StatsKingdom calculator

For each comparison:

1. Open the Mann–Whitney calculator:
   <https://www.statskingdom.com/170median_mann_whitney.html>
2. Select the option for **two independent samples**.
3. Enter the Vibe Coding participant values in one sample.
4. Enter the Traditional Coding participant values in the other sample.
5. Select a **two-sided** alternative for the comparisons in this document.
6. Record the reported `U` and `p-value`.

