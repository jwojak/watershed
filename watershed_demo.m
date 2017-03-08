function [] = watershed_demo()
%
% demo of the vincent_soille_watershed algo
%

%step 1: load an image
im_test = imread('lena512.bmp');
lena = im_test;

%step 2: proccess watershed
im_label_c4 = vincent_soille_watershed(im_test , 4);
im_label_c8 = vincent_soille_watershed(im_test , 8);

%step 3 display results
figure
imagesc(im_test);
title('input image');

figure
contour_c4 = im_test;
contour_c4(im_label_c4 ==0 ) = 0;
imagesc(contour_c4);
title('watershed connectivity 4')

figure
contour_c8 = im_test;
contour_c8(im_label_c8 ==0 ) = 0;
imagesc(contour_c8);
title('watershed connectivity 8')

disp('type enter to continu')
pause

%step 3.1 the same with a smoothed image
kernel = (1/(24.0*24.0))*ones(24,24);
im_test = conv2(double(im_test),kernel,'same');

%step 3.2: proccess watershed
im_label_c4 = vincent_soille_watershed(im_test , 4);
im_label_c8 = vincent_soille_watershed(im_test , 8);

%step 3.3 display results
figure
imagesc(im_test);
title('input image');

figure
contour_c4 = im_test;
contour_c4(im_label_c4 ==0 ) = 0;
imagesc(contour_c4);
title('watershed connectivity 4')

figure
contour_c8 = im_test;
contour_c8(im_label_c8 ==0 ) = 0;
imagesc(contour_c8);
title('watershed connectivity 8')


disp('type enter to continu')
pause


%step 3.1 the same with a gradient image
im_test = lena; 
kernel = (1/4.0)*[0,-1,0;-1,0,1;0,-1,0];
im_test = conv2(double(im_test),kernel,'same');

%step 3.2: proccess watershed
im_label_c4 = vincent_soille_watershed(im_test , 4);
im_label_c8 = vincent_soille_watershed(im_test , 8);

%step 3.3 display results
figure
imagesc(im_test);
title('input image');

figure
contour_c4 = im_test;
contour_c4(im_label_c4 ==0 ) = 0;
imagesc(contour_c4);
title('watershed connectivity 4')

figure
contour_c8 = im_test;
contour_c8(im_label_c8 ==0 ) = 0;
imagesc(contour_c8);
title('watershed connectivity 8')

end