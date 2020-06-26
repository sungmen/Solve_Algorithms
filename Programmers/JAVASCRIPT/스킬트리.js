let solution = (skill, skill_trees) => {
    return skill_trees.map(x => x.replace(new RegExp(`[^${skill}]`, 'g'), '')).filter(x => {return skill.indexOf(x) === 0 || x === "";}).length
}