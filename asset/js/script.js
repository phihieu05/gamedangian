const sliderItems = document.querySelectorAll(".slider-item");
for (let index = 0; index < sliderItems.length; index++) {
  sliderItems[index].style.left = index * 100 + "%";
}

const arrowRight = document.querySelector(".ri-arrow-right-fill");
const arrowLeft = document.querySelector(".ri-arrow-left-fill");
let i = 0;

arrowRight.addEventListener("click", () => {
  if (i < sliderItems.length - 1) {
    i++;
  } else {
    i = 0;
  }
  updateSlider();
});

arrowLeft.addEventListener("click", () => {
  if (i > 0) {
    i--;
  } else {
    i = sliderItems.length - 1;
  }
  updateSlider();
});

function updateSlider() {
  sliderItems.forEach((item, index) => {
    item.style.left = (index - i) * 100 + "%";
  });
}
setInterval(() => {
  if (i < sliderItems.length - 1) {
    i++;
  } else {
    i = 0;
  }
  updateSlider();
}, 5000);
